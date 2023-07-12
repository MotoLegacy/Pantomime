#ifndef _HTML_ATTRPARSE_H_
#define _HTML_ATTRPARSE_H_

#include "html_datatype.h"

extern void HTML_ParseAttributeContent(char* html_data, char* attribute_name, bool has_value,
                                        attribute_t* attributes, int* offset);

//
// Macros for attribute assigning
//

#define COLOR_FROM_NAME(compare, name, red, green, blue, location, res) { \
    if (res == 0 && strcasecmp(compare, name) == 0) { \
        res = 1; \
        location.r = red; \
        location.g = green; \
        location.b = blue; \
    } \
} \

#define GEN_FROM_VALUE(compare, value, ret, location, res) { \
    if (res == 0 && strcasecmp(compare, value) == 0) { \
        res = 1; \
        location = ret; \
    } \
} \

#define ATTR_DUPE_PRINT(attr) { \
    printf("HTML_ParseAttributeContent: Attribute '%s'" \
    " already defined. Ignoring duplicate definition.\n", \
    attr); \
} \

#define ASSIGN_TEXT_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != NULL) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseTextAttribute(content); \
        } \
    } \
}

#define ASSIGN_CSET_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != CS_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseCharsetsAttribute(content);\
        } \
    } \
}

#define ASSIGN_CONT_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != CTYPE_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseContentTypesAttribute(content);\
        } \
    } \
}

#define ASSIGN_CHAR_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != '\0') { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseContentTypesAttribute(content);\
        } \
    } \
}

#define ASSIGN_ALGN_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != ALIGN_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseAlignAttribute(content);\
        } \
    } \
}

#define ASSIGN_COLR_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location.used != false) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseColorAttribute(content);\
            location.used = true;\
        } \
    } \
}

#define ASSIGN_PIXL_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != -1) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParsePixelsAttribute(content);\
        } \
    } \
}

#define ASSIGN_LENG_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location.len != -1) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseLengthAttribute(content);\
        } \
    } \
}

#define ASSIGN_CLER_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != CLEAR_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseClearAttribute(content);\
        } \
    } \
}

#define ASSIGN_NUMB_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != -1) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseNumberAttribute(content);\
        } \
    } \
}

#define ASSIGN_CORD_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location.x != -1) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseCoordsAttribute(content);\
        } \
    } \
}

#define ASSIGN_TFRM_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != TF_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseTFrameAttribute(content);\
        } \
    } \
}

#define ASSIGN_MTHD_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != METHOD_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseMethodAttribute(content);\
        } \
    } \
}

#define ASSIGN_TRLE_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != TR_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseTRulesAttribute(content);\
        } \
    } \
}

#define ASSIGN_SCOP_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != SCOPE_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseScopeAttribute(content);\
        } \
    } \
}

#define ASSIGN_SCRL_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != SCROLL_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseScrollAttribute(content);\
        } \
    } \
}

#define ASSIGN_SHPE_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != SHAPE_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseShapeAttribute(content);\
        } \
    } \
}

#define ASSIGN_STYL_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != NULL) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseStyleSheetAttribute(content);\
        } \
    } \
}

#define ASSIGN_VALN_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != VA_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseVAlignAttribute(content);\
        } \
    } \
}

#define ASSIGN_VALT_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != VT_NONE) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = HTML_ParseValueTypeAttribute(content);\
        } \
    } \
}

#define ASSIGN_BOOL_ATTR(compare, string, location, content, res) { \
    if (strcasecmp(compare, string) == 0) { \
        res = 1; \
        if (location != false) { \
            ATTR_DUPE_PRINT(compare); \
        } else { \
            location = true;\
        } \
    } \
}

#endif // _HTML_ATTRPARSE_H_
