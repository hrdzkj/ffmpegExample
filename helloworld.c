
#include <stdio.h>
#include <string.h>

#include "libavformat/avformat.h"
#include "libavutil/dict.h"


#pragma comment(lib, "avformat.lib")
#pragma comment(lib, "avutil.lib")
#pragma comment(lib, "avcodec.lib")
/*
实现集成ffmpeg
*/
int openFile()
{
	AVFormatContext *fmt_ctx = NULL;
	AVDictionaryEntry *tag = NULL;
	int ret;

	char* inputFile = "test.mp4";
	av_register_all();
	if ((ret = avformat_open_input(&fmt_ctx, inputFile, NULL, NULL))) {
		char errbuf[100];
		ret = AVERROR(ret);
		av_strerror(ret, errbuf, sizeof(errbuf));

		av_log(NULL, AV_LOG_ERROR, "avformat_open_input Error=%s \n", errbuf);
		return ret;
	}
		

	while ((tag = av_dict_get(fmt_ctx->metadata, "", tag, AV_DICT_IGNORE_SUFFIX)))
		printf("%s=%s\n", tag->key, tag->value);

	avformat_close_input(&fmt_ctx);
	return 0;
}
int mainHelloWorld(void)
{
	openFile();
	char str[20] = "\0";  //字符数组初始化\0
	printf("请输入字符串：");
	system("pause");
	return 0;
}