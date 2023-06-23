#ifndef _HTMLATTRTYPES_H_
#define _HTMLATTRTYPES_H_

#include "types.h"

//
// HTML Attribute Types
//

//==== %Text; ====//
typedef char text_t;


//==== %Charsets; ====//
typedef enum {
    CS_ASCII, 
    CS_ANSI, 
    CS_ISO8859, 
    CS_UTF8
} charsets_t;

//==== %ContentTypes; ====//
// NOTE: This doesn't necessarily represent the browser's
// supported content types. this is just everything in 
// accordance to geeksforgeeks' spec.
// (https://www.geeksforgeeks.org/http-headers-content-type/)
typedef enum {
    // Application
    CTYPE_APP_EDIX12,
    CTYPE_APP_EDIFACT,
    CTYPE_APP_JS,
    CTYPE_APP_OCTETSTREAM,
    CTYPE_APP_OGG,
    CTYPE_APP_PDF,
    CTYPE_APP_XHTMLXML,
    CTYPE_APP_XSHOCKWAVEFLASH,
    CTYPE_APP_JSON,
    CTYPE_APP_LDJSON,
    CTYPE_APP_XML,
    CTYPE_APP_ZIP,
    CTYPE_APP_XWWWFORMURLENCODED,
    // Audio
    CTYPE_AUD_MPEG,
    CTYPE_AUD_XMASWMA,
    CTYPE_AUD_VNDRNREALAUDIO,
    CTYPE_AUD_XWAV,
    // Image
    CTYPE_IMG_GIF,
    CTYPE_IMG_JPEG,
    CTYPE_IMG_PNG,
    CTYPE_IMG_TIFF,
    CTYPE_IMG_VNDMICROSOFTICON,
    CTYPE_IMG_XICON,
    CTYPE_IMG_VNDDJVU,
    CTYPE_IMG_SVGXML,
    // Multipart
    CTYPE_MPA_MIXED,
    CTYPE_MPA_ALTERNATIVE,
    CTYPE_MPA_RELATED,
    CTYPE_MPA_FORMDATA,
    // Text
    CTYPE_TXT_CSS,
    CTYPE_TXT_CSV,
    CTYPE_TXT_HTML,
    CTYPE_TXT_JS,
    CTYPE_TXT_PLAIN,
    CTYPE_TXT_XML,
    // Video
    CTYPE_VID_MPEG,
    CTYPE_VID_MP4,
    CTYPE_VID_QUICKTIME,
    CTYPE_VID_XMSWMV,
    CTYPE_VID_XMSVIDEO,
    CTYPE_VID_XFLV,
    CTYPE_VID_WEBM,
    // 'VND' (?)
    CTYPE_APP_VNDOASISOPENDOCUMENTTEXT,
    CTYPE_APP_VNDOASISOPENDOCUMENTSPREADSHEET,
    CTYPE_APP_VNDOASISOPENDOCUMENTPRESENTATION,
    CTYPE_APP_VNDOASISOPENDOCUMENTGRAPHICS,
    CTYPE_APP_VNDMSEXCEL,
    CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTSPREADSHEET,
    CTYPE_APP_VNDMSPOWERPOINT,
    CTYPE_APP_VNDOPENXMLFORMATS,
    CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTPRESENTATIONMLPRESENTATION,
    CTYPE_APP_MSWORD,
    CTYPE_APP_VNDOPENXMLFORMATSOFFICEDOCUMENTWORDPROCESSINGMLDOCUMENT,
    CTYPE_APP_VNDMOZILLAXULXML
} contenttypes_t;

//==== %Character; ====//
typedef char character_t;

//==== %URI; ====//
typedef char uri_t;

//==== %Color; ====//
typedef struct {
    byte r;
    byte g;
    byte b;
} color_t;

//==== CDATA ====//
//(https://www.w3.org/TR/html4/types.html#type-cdata)
typedef char cdata_t;

//==== %Pixels; ====//
typedef int pixels_t;

//==== %Length; ====//
typedef struct {
    int len;

    enum {
        LEN_PIXEL,
        LEN_EM,
        LEN_EX,
        LEN_CH,
        LEN_REM,
        LEN_VW,
        LEN_VH,
        LEN_VMIN,
        LEN_VMAX,
        LEN_PERCENT
    } type;
} length_t;

//==== %MultiLengths; ====//
typedef length_t multilengths_t;

//==== NUMBER ====//
//(https://www.w3.org/TR/html4/types.html#type-number)
typedef double number_t;

//==== %Coords; ====//
typedef struct {
    unsigned int x;
    unsigned int y;
    unsigned int w;
    unsigned int h;
} coords_t;

//==== %Datetime; ====//
typedef char datetime_t;

//==== IDREF ====//
//(https://www.w3.org/TR/html4/types.html#type-idref)
typedef char idref_t;

//==== IDREFS ====//
typedef idref_t idrefs_t;

//==== %TFrame; ====//
typedef enum {
    TF_VOID,
    TF_ABOVE,
    TF_BELOW,
    TF_HSIDES,
    TF_LHS,
    TF_RHS,
    TF_VSIDES,
    TF_BOX,
    TF_BORDER
} tframe_t;

//==== %LanguageCode; ====//
typedef char languagecode_t;

//==== ID ====//
//(https://www.w3.org/TR/html4/types.html#type-id)
typedef char _id_t;

//==== NAME ====//
typedef _id_t name_t;

//==== %MediaDesc; ====//
typedef char mediadesc_t;

//==== %LinkTypes; ====//
typedef char linktypes_t;

//==== %TRules; ====//
typedef enum {
    TR_NONE,
    TR_GROUPS,
    TR_ROWS,
    TR_COLS,
    TR_ALL
} trules_t;

//==== %Scope; ====//
typedef enum {
    SCOPE_ROW,
    SCOPE_COL,
    SCOPE_ROWGROUP,
    SCOPE_COLGROUP
} scope_t;

//==== %Shape; ====//
typedef enum {
    SHAPE_RECT,
    SHAPE_CIRCLE,
    SHAPE_POLY,
    SHAPE_DEFAULT
} shape_t; 

//==== %StyleSheet; ====//
typedef char stylesheet_t;

//==== %FrameTarget; ====//
typedef char frametarget_t;

//==== %InputType; ====//
typedef enum {
    IT_TEXT,
    IT_PASSWORD,
    IT_CHECKBOX,
    IT_RADIO,
    IT_SUBMIT,
    IT_RESET,
    IT_FILE,
    IT_HIDDEN,
    IT_IMAGE,
    IT_BUTTON
} inputtype_t;

//==== %ULStyle; ====//
typedef enum {
    UL_DISC,
    UL_SQUARE,
    UL_CIRCLE
} ulstyle_t;

// Off-spec

//==== %CAlign;, %IAlign;, %LAlign;, %TAlign; ====//
typedef enum {
    ALIGN_TOP,
    ALIGN_LEFT,
    ALIGN_CENTER,
    ALIGN_RIGHT,
    ALIGN_BOTTOM,
    ALIGN_MIDDLE,
    ALIGN_JUSTIFY,
    ALIGN_CHAR
} align_t;

//==== %Button; ====//
typedef enum {
    BUT_BUTTON,
    BUT_SUBMIT,
    BUT_RESET
} button_t;

//==== %Scroll; ====//
typedef enum {
    SCROLL_YES,
    SCROLL_NO,
    SCROLL_AUTO
} scroll_t;

//==== %LIStyle;, %OLStyle;  ====//
typedef char style_t;

//==== %VAlign; ====//
typedef enum {
    VA_TOP,
    VA_MIDDLE,
    VA_BOTTOM,
    VA_BASELINE
} valign_t;

//==== %ValueType; ====//
typedef enum {
    VT_DATA,
    VT_REF,
    VT_OBJECT
} valuetype_t;

//==== %Clear; ====//
typedef enum {
    CLEAR_LEFT,
    CLEAR_RIGHT,
    CLEAR_ALL,
    CLEAR_NONE
} clear_t;

//==== %Method; ====//
typedef enum {
    METHOD_GET,
    METHOD_POST
} method_t;

#endif // _HTMLATTRTYPES_H_
