#include <stdio.h>
#include <libavutil/avutil.h>

int main(int argc, char const *argv[])
{
    printf("%s\n", av_version_info());
    return 0;
}
