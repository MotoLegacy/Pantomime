#ifndef _HTML_H_
#define _HTML_H_

#define MAX_TAG_LEN         16
#define MAX_ATTR_NAME_LEN   32
#define MAX_ATTR_VAL_LEN    512
// #define MAX_ATTR_CONTENT_LEN     512 // TODO, also find shorter name for this

extern void HTML_BeginParse(char* html_data);

#endif // _HTML_H_
