/***************************************************************************
 *
 * CURL DEMO FOR OBS-WHIP TEST
 *
 ***************************************************************************/

#include <curl/curl.h>

#include <stdio.h>
#include <string>

#define LOCATION_HEADER_LENGTH 10

static const char *astrblank = "";

int astrcmpi_n(const char *str1, const char *str2, size_t n) {
  if (!n) return 0;
  if (!str1) str1 = astrblank;
  if (!str2) str2 = astrblank;

  do {
    char ch1 = (char)toupper(*str1);
    char ch2 = (char)toupper(*str2);

    if (ch1 < ch2)
      return -1;
    else if (ch1 > ch2)
      return 1;
  } while (*str1++ && *str2++ && --n);

  return 0;
}

static std::string trim_string(const std::string &source) {
  std::string ret(source);
  ret.erase(0, ret.find_first_not_of(" \n\r\t"));
  ret.erase(ret.find_last_not_of(" \n\r\t") + 1);
  return ret;
}

static size_t curl_header_location_function(char *data, size_t size,
                                            size_t nmemb, void *priv_data) {

  // printf("curl_header_location_function has been invoked\n");
  // auto header_buffer = static_cast<std::string *>(priv_data);
  auto header_buffer = static_cast<std::vector<std::string> *>(priv_data);

  size_t real_size = size * nmemb;

  if (real_size < LOCATION_HEADER_LENGTH) return real_size;

  if (!astrcmpi_n(data, "location: ", LOCATION_HEADER_LENGTH)) {
    char *val = data + LOCATION_HEADER_LENGTH;
    // header_buffer->append(val, real_size - LOCATION_HEADER_LENGTH);
    auto header_temp = std::string(val, real_size - LOCATION_HEADER_LENGTH);
    header_temp = trim_string(header_temp);
    header_buffer->push_back(header_temp);
  }

  return real_size;
}

static size_t curl_writefunction(char *data, size_t size, size_t nmemb,
                                 void *priv_data) {
  // printf("curl_writefunction has been invoked\n");
  auto read_buffer = static_cast<std::string *>(priv_data);

  size_t real_size = size * nmemb;

  read_buffer->append(data, real_size);
  return real_size;
}

int main(void) {
  struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Content-Type: application/sdp");
  char bearer_token_header[] =
      "Authorization: Bearer abcdefghijklmnopqrstuvwxyz";
  headers = curl_slist_append(headers, bearer_token_header);

  std::string read_buffer;
  std::vector<std::string> location_headers;
  std::string endpoint_url = "http://localhost:8082/whip";

  char offer_sdp[] = "sdp_offer";

  CURL *c = curl_easy_init();
  curl_easy_setopt(c, CURLOPT_WRITEFUNCTION, curl_writefunction);
  curl_easy_setopt(c, CURLOPT_WRITEDATA, (void *)&read_buffer);
  curl_easy_setopt(c, CURLOPT_HEADERFUNCTION, curl_header_location_function);
  curl_easy_setopt(c, CURLOPT_HEADERDATA, (void *)&location_headers);
  curl_easy_setopt(c, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(c, CURLOPT_URL, endpoint_url.c_str());
  curl_easy_setopt(c, CURLOPT_POST, 1L);
  curl_easy_setopt(c, CURLOPT_COPYPOSTFIELDS, offer_sdp);
  curl_easy_setopt(c, CURLOPT_TIMEOUT, 8L);
  curl_easy_setopt(c, CURLOPT_FOLLOWLOCATION, 1L);
  curl_easy_setopt(c, CURLOPT_UNRESTRICTED_AUTH, 1L);

  auto cleanup = [&]() {
    curl_easy_cleanup(c);
    curl_slist_free_all(headers);
  };

  CURLcode res = curl_easy_perform(c);
  if (res != CURLE_OK) {
    printf("Connect failed: CURL returned result not CURLE_OK\n");
    cleanup();
    return -1;
  }

  long response_code;
  curl_easy_getinfo(c, CURLINFO_RESPONSE_CODE, &response_code);
  if (response_code != 201) {
    printf("Connect failed: HTTP endpoint returned response code %ld\n", response_code);
    cleanup();
    return -1;
  }

  if (read_buffer.empty()) {
    printf("Connect failed: No data returned from HTTP endpoint request\n");
    cleanup();
    return -1;
  }

  long redirect_count = 0;
  res = curl_easy_getinfo(c, CURLINFO_REDIRECT_COUNT, &redirect_count);
  if (CURLE_OK != res) {
      printf("Connect failed: can not get redirect count\n");
      cleanup();
      return -1;
  }

  if (location_headers.size() != redirect_count + 1) {
    printf("WHIP server did not provide a resource URL via the Location header. redirect time: %ld, location head size: %lu \n", redirect_count, location_header.size());
  } else {
    CURLU *h = curl_url();
    // curl_url_set(h, CURLUPART_URL, endpoint_url.c_str(), 0);
    curl_url_set(h, CURLUPART_URL, location_headers.back().c_str(), 0);
    char *url = nullptr;
    CURLUcode rc = curl_url_get(h, CURLUPART_URL, &url, CURLU_NO_DEFAULT_PORT);
    if (!rc) {
      std::string resource_url = url;
      curl_free(url);
      printf("WHIP Resource URL is: %s\n", resource_url.c_str());
    } else {
      printf("Unable to process resource URL response\n");
    }
    curl_url_cleanup(h);
  }

  cleanup();
  return 0;
}
