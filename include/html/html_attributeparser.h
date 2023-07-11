#ifndef _HTML_ATTRPARSE_H_
#define _HTML_ATTRPARSE_H_

#include "html_datatype.h"

extern void HTML_ParseAttributeContent(char* html_data, char* attribute_name, bool has_value,
                                        attribute_t* attributes, int* offset);

#endif // _HTML_ATTRPARSE_H_
