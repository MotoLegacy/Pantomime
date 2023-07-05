//
// Copyright (C) 2023 by Ivy Bowling <motolegacy.git@gmail.com>
//
// Permission to use, copy, modify, and/or distribute this software 
// for any purpose with or without fee is hereby granted.
// 
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL 
// WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED 
// WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL 
// THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM 
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, 
// NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN 
// CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include <util.h>
#include <html/html_parser.h>
#include <html/html_attributeparser.h>
#include <html/html_datatype.h>

extern byte HTML_GetIDFromTagString(char* tag_name);

/*
 * TODO
 * - Add support for the "type" attribute.
 * - Make the DOM Tree.
 */

void HTML_ParseUselessLine(char* html_data, int* offset)
{
    // First off -- determine if this is a comment.
    bool line_is_comment;

    if (html_data[*offset] == '-' && html_data[*offset + 1] == '-')
        line_is_comment = true;
    else
        line_is_comment = false;

    // Just like BeginParse, iterate through the HTML
    // document.
    int i;
    for (i = *offset; i < strlen(html_data); i++) {
        // Skip to a potential tag end.
        if (html_data[i] == '>') {
            if (line_is_comment) {
                // Iterate backwards to see if the >
                // had the end-of-comment identifier.
                if (html_data[i - 1] == '-' && html_data[i - 2] == '-')
                    break;
            } else {
                // Was DOCTYPE, or something else
                // equally stupid. We can leave.
                break;
            }
        }
    }
    *offset = i;
}

void HTML_ParseAttribute(char* html_data, element_t* element, int* offset)
{
    bool attr_seeking = true;

    while(attr_seeking == true) {
        // Allocate memory for the attribute name
        char* attribute_name = malloc(sizeof(char)*MAX_ATTR_NAME_LEN);
        int attr_offset = 0;
        bool has_value = true;
        int i;

        for(i = 0; i < MAX_ATTR_NAME_LEN; i++) {
            // '>' Indicates we've reached the end of the line.
            if (html_data[i + *offset] == '>') {
                attr_seeking = false;
                has_value = false;
                i += 1;
                break;
            }
            // We've hit an end quote. 
            else if (html_data[i + *offset] == '"') {
                continue;
            }
            // Whitespace
            else if (html_data[i + *offset] == ' ' && i != 0) {
                // Check to see if this is just a random space
                // before attribute content
                if (html_data[i + *offset + 1] != '=') {
                    has_value = false;
                    i++;
                    break;
                }
                // It was, so carry on.
                else {
                    continue;
                }
            }
            // checks if there are multiple tags in one line, this will just end on first occurance
            else if (html_data[i + *offset] == ' ' && html_data[i + *offset+1] != ' ') {
				attr_offset = '\0';
				continue;
            }
            // Non-boolean attributes will end with '='.
            else if (html_data[i + *offset] == '=') {
                i += 2;
                break;
            } 

            attribute_name[attr_offset] = html_data[i + *offset];
            attribute_name[attr_offset + 1] = '\0';
            attr_offset++;
        }

        // Increment the parsing index.
        *offset += i;

        // Now that we have the name we can begin parsing the content
        HTML_ParseAttributeContent(html_data, attribute_name, has_value, 
                                    &element->attributes, offset);

        // Free Buffer
        free(attribute_name);

        if (html_data[*offset] == '>') {
            attr_seeking = false;
            break;
        }
    }
}

//
// HTML_ParseStartTag
// -----
// Identifies the element name in a starting tag of an
// HTML document. Returns 0 if there are no attributes
// and 1 if it identifies a potential attribute.
//
element_t HTML_ParseStartTag(char* html_data, int* offset)
{
    // Element data structure to return.
    element_t new_element;
    new_element.has_attributes = false;

    // Allocate memory for the string that holds the
    // tag name.
    char* tag_name = malloc(sizeof(char)*MAX_TAG_LEN);

    // Store the offset index for the tag parsing.
    int tag_offset = 0;

    // Just like BeginParse, iterate through the HTML
    // document.
    int i;
    for (i = 0; i < MAX_TAG_LEN; i++) {
        // End of tag, break off.
        if (html_data[i + *offset] == '>')
            break;
        // Space -- element name is over, attributes
        // potentially follow.
        if (html_data[i + *offset] == ' ') {
            new_element.has_attributes = true;
            break;
        }

        // Otherwise, append to tag name.
        tag_name[tag_offset] = html_data[i + *offset];
        tag_name[tag_offset + 1] = '\0';
        tag_offset++;
    }

    // Create an element from the tag char*.
    new_element.tag = HTML_GetIDFromTagString(tag_name);

    *offset += i + 1;

    return new_element;
}

void HTML_ParseEndTag(char* html_data, int* offset)
{
    // Allocate memory for the string that holds the
    // tag name.
    char* tag_name = malloc(sizeof(char)*MAX_TAG_LEN);

    // Store the offset index for the tag parsing.
    int tag_offset = 0;

    // Just like BeginParse, iterate through the HTML
    // document.
    int i;
    for (i = 0; i < MAX_TAG_LEN; i++) {
        // End of tag, break off.
        if (html_data[i + *offset] == '>')
            break;

        // Otherwise, append to tag name.
        tag_name[tag_offset] = html_data[i + *offset];
        tag_name[tag_offset + 1] = '\0';
        tag_offset++;
    }

    // Create an element from the tag char*.
    element_t elem;
    elem.tag = HTML_GetIDFromTagString(tag_name);

    *offset += i;
}

char* HTML_CleanDocument(char* html_data)
{
    int i = 0;
    bool scrubbing = true;

    while(scrubbing) {
        // We found a newline.
        if (html_data[i] == '\n') {
            // Iterate over to get first character
            // of the new line.
            i++;

            // While everything after the new line is a space
            // or a tab, re-build the document data without it.
            while(html_data[i] == ' ' || html_data[i] == '\t') {
                html_data = Util_CharDeleteAtIndex(html_data, i);
            }
        } 
        // We found a standard space (' ')
        else if (html_data[i] == ' ') {
            // Increment the index by one.
            i++;

            bool multiple_spaces = true;
            while(multiple_spaces) {
                // Is this slot a space, too?
                if (html_data[i] == ' ') {
                    html_data = Util_CharDeleteAtIndex(html_data, i);
                } 
                // It wasn't, stop trying to scrub.
                else {
                    multiple_spaces = false;
                }
            }
        } else {
            // Increment the index, look at next character.
            i++;
        }

        // EoF? Leave.
        if (i >= strlen(html_data) || html_data[i] == '\0') {
            scrubbing = false;
        }
    }

    return html_data;
}

void HTML_BeginParse(char* html_data)
{
    // Scrub the document of any trailing/leading whitespace.
    html_data = HTML_CleanDocument(html_data);

    // Start by iterating through the data character by
    // character.
    for (int i = 0; i < strlen(html_data); i++) {
        // Document has a start-of-tag identifier.
        if (html_data[i] == '<') {
            // First off, is this actually a tag?
            // Tags will not have a space following
            // the start identifier.
            if (html_data[i + 1] == ' ') {
                // It's not a tag. Continue.
                continue;
            }
            // Is this a '!' style tag (DOCTYPE or
            // comment)? If so, also ignore it.
            else if (html_data[i + 1] == '!') {
                i += 2;
                HTML_ParseUselessLine(html_data, &i);
            }
            // Next, is this the start of a tag or
            // an end? Tag ends will follow with a
            // forward slash (/).
            else if (html_data[i + 1] == '/') {
                i += 2;
                HTML_ParseEndTag(html_data, &i);
            }
            // Make a (good!) assumption this is the
            // beginning of an element.
            else {
                i += 1;

                element_t new_element = HTML_ParseStartTag(html_data, &i);

                // We identified that there is potential for there to
                // be attributes, so try and parse them.
                if (new_element.has_attributes == true) {
                    HTML_ParseAttribute(html_data, &new_element, &i);
                }
            }
        }
    }
}
