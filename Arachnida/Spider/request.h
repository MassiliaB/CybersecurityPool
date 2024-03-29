#ifndef REQUEST_H
#define REQUEST_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <curl/curl.h>
#include "libxml/HTMLparser.h"
#include "libxml/xpath.h"

#define D_PATH "data/"
#define D_VALUE 5

typedef struct s_data {

    int		opt_r;
    int		opt_l;
    char	*opt_p;
    char	*url;

} t_data;

struct CURLResp
{
	char	*html;
	size_t	size;
};

struct Images {
    char**	urls;
    size_t	count;
	char**	ext;
};

int				request(struct CURLResp *resp, const char *url);
struct CURLResp	GetRequest(const char *url);
void			scrapeImages(const char* htmlContent, struct Images* imgUrls, int currentDepth, int maxDepth);
void			freeImg(struct Images* imgUrls);
int				downloadImage(const char* url, const char* ext, const char* path);

#endif