// SharedInstanceGCD.h
//
// Copyright (c) 2012 Tim Shadel & others (http://github.com/timshadel)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#ifndef SHARED_INSTANCE_GCD
#define SHARED_INSTANCE_GCD \
\
+ (instancetype)sharedInstance { \
    DEFINE_SHARED_INSTANCE_GCD_USING_BLOCK(^{ \
      return [[self alloc] init]; \
    }) \
}
#endif

#ifndef SHARED_INSTANCE_GCD_USING_BLOCK
#define SHARED_INSTANCE_GCD_USING_BLOCK(block) \
\
+ (instancetype)sharedInstance { \
    DEFINE_SHARED_INSTANCE_GCD_USING_BLOCK(block) \
}
#endif

#ifndef SHARED_INSTANCE_GCD_WITH_NAME
#define SHARED_INSTANCE_GCD_WITH_NAME(classname)                        \
\
+ (instancetype)shared##classname { \
    DEFINE_SHARED_INSTANCE_GCD_USING_BLOCK(^{ \
      return [[self alloc] init]; \
    }) \
}                                                           
#endif

#ifndef SHARED_INSTANCE_GCD_WITH_NAME_USING_BLOCK
#define SHARED_INSTANCE_GCD_WITH_NAME_USING_BLOCK(classname, block) \
\
+ (instancetype)shared##classname { \
    DEFINE_SHARED_INSTANCE_GCD_USING_BLOCK(block) \
}                                                           
#endif

#ifndef DEFINE_SHARED_INSTANCE_GCD_USING_BLOCK
#define DEFINE_SHARED_INSTANCE_GCD_USING_BLOCK(block) \
    static dispatch_once_t pred = 0; \
    __strong static id _sharedObject = nil; \
    dispatch_once(&pred, ^{ \
      _sharedObject = block(); \
    }); \
    return _sharedObject;
#endif


