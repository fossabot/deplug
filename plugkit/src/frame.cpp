#include "private/frame.hpp"
#include "wrapper/frame.hpp"

namespace plugkit {

FrameUniquePtr Frame::Private::create() {
  FrameUniquePtr frame(new Frame());
  return frame;
}

Frame::Frame() : d(new Private()) {}

Frame::~Frame() {}

Frame::Timestamp Frame::timestamp() const { return d->timestamp(); }

Frame::Timestamp Frame::Private::timestamp() const { return timestamp_; }

void Frame::Private::setTimestamp(const Timestamp &timestamp) {
  timestamp_ = timestamp;
}

size_t Frame::length() const { return d->length(); }

size_t Frame::Private::length() const { return length_; }

void Frame::Private::setLength(size_t length) { length_ = length; }

uint32_t Frame::seq() const { return d->seq(); }

uint32_t Frame::Private::seq() const { return seq_; }

void Frame::Private::setSeq(uint32_t seq) { seq_ = seq; }

LayerPtr Frame::rootLayer() const { return d->rootLayer(); }

LayerPtr Frame::Private::rootLayer() const { return layer_; }

void Frame::Private::setRootLayer(const LayerPtr &layer) { layer_ = layer; }
}