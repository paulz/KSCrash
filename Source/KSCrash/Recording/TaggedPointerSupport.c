//
//  TaggedPointerSupport.c
//  KSCrash-iOS
//
//  Created by Paul Zabelin on 6/24/19.
//  Copyright © 2019 Karl Stenerud. All rights reserved.
//

#include "TaggedPointerSupport.h"

#include <CoreFoundation/CoreFoundation.h>
#include "KSObjCApple.h"
#include "objc-internal.h"


void initializeTagPointers() {
    if (objc_debug_taggedpointer_obfuscator) {
        return;
    }
    const UInt8 bytes = 0x61;
    uintptr_t obfuscatedPtr = (uintptr_t)CFStringCreateWithBytes(NULL,
                                                                 &bytes,
                                                                 1,
                                                                 kCFStringEncodingUTF8,
                                                                 FALSE);
    uintptr_t unobfuscatedPtr = (uintptr_t)_objc_makeTaggedPointer(OBJC_TAG_NSString, bytes);
    objc_debug_taggedpointer_obfuscator = obfuscatedPtr ^ unobfuscatedPtr;
}
