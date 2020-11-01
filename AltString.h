/*
 *
 * AltString.h
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

#ifndef INCLUDE_STDIO_H
#define INCLUDE_STDIO_H

#include <stdio.h>

#endif

#ifndef INCLUDE_STDLIB_H
#define INCLUDE_STDLIB_H

#include <stdlib.h>

#endif

#ifndef INCLUDE_STRING_H
#define INCLUDE_STRING_H

#include <string.h>

#endif

#ifndef DECLARE_ALT_STRING_H
#define DECLARE_ALT_STRING_H

typedef struct altString {
    int errorLevel;
    int length;
    char * value;

    int (* getErrorLevel)(struct altString *);

    int (* getLength)(struct altString *);

    char * (* get)(struct altString *);

    int (* indexOf)(struct altString *, const char);

    char * (* subString)(struct altString *, int, int);

    char * (* cut)(struct altString *, const char);

    void (* dispose)(struct altString *);
} AltString;

AltString * AltString_init(char *);

#endif
