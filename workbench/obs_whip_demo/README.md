

## Nginx Config

```
server {
    listen       8082;
    server_name  localhost;
    location /whip {
        return 307 $scheme://localhost:8083/redirect;
    }
}

server {
    listen       8083;
    server_name  localhost;
    location /redirect {
        add_header Location 'http://localhost:8084/whip_resource';
        return 201 'sdp_answer';
    }
}
```

## Build Command

```
cmake -Bbuild
cmake --build ./build
./build/curl_hello
```

## Result

```
WHIP Resource URL is: http://localhost:8084/whip_resource
```