#include <v8.h>
#include <node.h>
#include <node_buffer.h>
#include <cstring>

using namespace v8;
using namespace node;

static Handle<Value>
VException(const char *msg) {
    HandleScope scope;
    return ThrowException(Exception::Error(String::New(msg)));
}

Handle<Value>
EqBuf(const Arguments &args)
{
    HandleScope scope;

    if (args.Length() != 2)
        return VException("Two arguments required - buffer1 and buffer2");

    if (!Buffer::HasInstance(args[0]))
        return VException("First argument must be Buffer.");
    if (!Buffer::HasInstance(args[1]))
        return VException("Second argument must be Buffer.");

    Buffer *buf1 = ObjectWrap::Unwrap<Buffer>(args[0]->ToObject()); 
    Buffer *buf2 = ObjectWrap::Unwrap<Buffer>(args[1]->ToObject()); 

    if (buf1->length() != buf2->length())
        return scope.Close(False());

    return scope.Close(
        Boolean::New(memcmp(buf1->data(), buf2->data(), buf1->length())==0)
    );
}

extern "C" void
init(Handle<Object> target)
{
    HandleScope scope;
    target->Set(String::New("eqBuf"), FunctionTemplate::New(EqBuf)->GetFunction());
}

