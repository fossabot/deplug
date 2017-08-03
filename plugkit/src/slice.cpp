#include "slice.hpp"

namespace plugkit {
class Slice::Private {
public:
  Private(const char *buf, size_t offset, size_t length);

public:
  const char *buf;
  size_t buflen;
  size_t offset;
  size_t length;
};

Slice::Private::Private(const char *buf, size_t offset, size_t length)
    : buf(buf), buflen(length), offset(offset), length(length) {}

Slice::Slice() : d(new Private(nullptr, 0, 0)) {}

Slice::~Slice() {}

Slice::Slice(const char *data, size_t length)
    : d(new Private(data, 0, length)) {}

Slice::Slice(const Slice &slice) : d(new Private(*slice.d)) {}

Slice &Slice::operator=(const Slice &slice) {
  d.reset(new Private(*slice.d));
  return *this;
}

const char *Slice::data() const {
  if (d->buf && d->offset < d->buflen)
    return &d->buf[d->offset];
  return nullptr;
}

size_t Slice::length() const { return d->length; }

char Slice::operator[](size_t index) const { return d->buf[d->offset + index]; }

size_t Slice::offset() const { return d->offset; }

Slice Slice::slice(size_t offset, size_t length) const {
  if (!d->buf)
    return Slice();
  auto clip = [](size_t value, size_t max) {
    return value > max ? max : value;
  };
  size_t s = this->length();
  size_t newOffset = clip(d->offset + offset, d->offset + s);
  size_t newLength = clip(clip(length, d->buflen - newOffset), s);
  return Slice(d->buf + newOffset, newLength);
}

Slice Slice::slice(size_t offset) const {
  return slice(offset, length() - offset);
}
}
