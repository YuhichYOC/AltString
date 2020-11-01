/*
 *
 * AltString.c
 *
 * Copyright 2020 Yuichi Yoshii
 *     吉井雄一 @ 吉井産業  you.65535.kir@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "AltString.h"

char * alsString_charAllocate(AltString *, unsigned long);

void alsString_skip(AltString *, int);

int alsString_getErrorLevel(AltString * s) {
    return s->errorLevel;
}

int alsString_getLength(AltString * s) {
    return s->length;
}

char * alsString_get(AltString * s) {
    return s->value;
}

int alsString_indexOf(AltString * s, const char arg) {
    for (int i = 0; s->length > i; ++i) {
        if (arg == s->value[i]) {
            return i;
        }
    }
    return -1;
}

char * alsString_subString(AltString * s, int from, int to) {
    if (to <= from) {
        s->errorLevel = 4;
        return NULL;
    }
    int l = to - from;
    char * ret = alsString_charAllocate(s, l + 1);
    if (0 < s->errorLevel) {
        return NULL;
    }
    for (int i = 0; l + 1 > i; ++i) {
        ret[i] = 0;
    }
    for (int j = 0; l > j; ++j) {
        ret[j] = s->value[from + j];
    }
    return ret;
}

char * alsString_cut(AltString * s, const char arg) {
    int cutPosition = s->indexOf(s, arg);
    if (-1 == cutPosition) {
        return NULL;
    }
    char * ret = alsString_charAllocate(s, cutPosition + 1);
    if (0 < s->errorLevel) {
        return NULL;
    }
    for (int i = 0; cutPosition + 1 > i; ++i) {
        ret[i] = 0;
    }
    for (int j = 0; cutPosition > j; ++j) {
        ret[j] = s->value[j];
    }
    alsString_skip(s, cutPosition);
    if (0 < s->errorLevel) {
        return NULL;
    }
    return ret;
}

void alsString_dispose(AltString * s) {
    free(s->value);
    free(s);
}

AltString * AltString_init(char * arg) {
    AltString * s = (AltString *) malloc(sizeof(AltString));
    s->errorLevel = 0;
    if (NULL == s) {
        return NULL;
    }
    s->length = (int) strlen(arg);
    s->value = alsString_charAllocate(s, s->length + 1);
    if (0 < s->errorLevel) {
        return NULL;
    }
    for (int i = 0; s->length + 1 > i; ++i) {
        s->value[i] = 0;
    }
    for (int j = 0; s->length > j; ++j) {
        s->value[j] = arg[j];
    }
    s->get = alsString_get;
    s->getLength = alsString_getLength;
    s->indexOf = alsString_indexOf;
    s->subString = alsString_subString;
    s->cut = alsString_cut;
    s->getErrorLevel = alsString_getErrorLevel;
    s->dispose = alsString_dispose;
    return s;
}

char * alsString_charAllocate(AltString * s, unsigned long length) {
    char * ret = (char *) malloc((size_t) length);
    if (NULL == ret) {
        s->errorLevel = 1;
        return NULL;
    }
    return ret;
}

void alsString_skip(AltString * s, int cutPosition) {
    int leftChars = s->length - cutPosition;
    for (int i = 0; leftChars + 1 > i; ++i) {
        s->value[i] = s->value[cutPosition + i];
    }
    for (int j = leftChars + 1; s->length > j; ++j) {
        s->value[j] = 0;
    }
    s->length = leftChars;
}
