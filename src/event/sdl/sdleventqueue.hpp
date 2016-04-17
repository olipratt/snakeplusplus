#include <queue>

#include <scene_event.hpp>

class SDLSceneEventQueue
{
public:
  void poll();
  bool empty() const { return event_queue_.empty(); }
  bool quit() const { return quit_; }
  SceneEvent front() const { return event_queue_.front(); }
  void pop() { event_queue_.pop(); }

private:
  std::queue<SceneEvent> event_queue_{};
  bool quit_{false};
};
