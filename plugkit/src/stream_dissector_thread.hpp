#ifndef PLUGKIT_STREAM_DISSECTOR_THREAD_H
#define PLUGKIT_STREAM_DISSECTOR_THREAD_H

#include "worker_thread.hpp"
#include <memory>
#include <vector>

namespace plugkit {

class Frame;
struct Layer;

struct Variant;

struct Dissector;

class StreamDissectorThread final : public WorkerThread {
public:
  using Callback = std::function<void(uint32_t)>;

public:
  StreamDissectorThread(const Variant &options, const Callback &callback);
  ~StreamDissectorThread() override;
  void pushStreamDissector(const Dissector &diss);
  void enter() override;
  bool loop() override;
  void exit() override;
  void push(Layer **begin, size_t size);
  void stop();

private:
  class Private;
  std::unique_ptr<Private> d;
};
} // namespace plugkit

#endif
