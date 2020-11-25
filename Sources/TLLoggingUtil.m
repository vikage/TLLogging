//
//  LoggingUtil.c
//
//  Created by Thanh Vu on 25/11/2020.
//  Copyright © 2020 Solar. All rights reserved.
//

#include "TLLoggingUtil.h"

void Objc_DCHECK(bool value, NSString *file, NSString *func, int line) {
    DEBUGCHECK(value, file, func, line);
}
