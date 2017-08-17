/// @file
/// Payload
#ifndef PLUGKIT_PAYLOAD_H
#define PLUGKIT_PAYLOAD_H

#include <stddef.h>
#include "token.h"
#include "slice.h"
#include "export.h"

PLUGKIT_NAMESPACE_BEGIN

struct Payload;
typedef struct Payload Payload;

struct Property;
typedef struct Property Property;

/// Returns the payload data.
PLUGKIT_EXPORT Slice Payload_data(const Payload *payload);

/// Allocates a new Property and adds it as a payload property.
PLUGKIT_EXPORT Property *Payload_addProperty(Payload *payload, Token id);

/// Gets type
PLUGKIT_EXPORT Token Payload_type(const Payload *payload);

/// Sets type
PLUGKIT_EXPORT void Payload_setType(Payload *payload, Token type);

PLUGKIT_NAMESPACE_END

#endif
