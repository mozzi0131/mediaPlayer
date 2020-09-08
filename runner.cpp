#include <glib.h>
#include <string>
#include <vector>

#include "pipeline/pipeline.hpp"

int main(){
  GThread *thread1 = StartThread(pipe1, "https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_cropped_multilingual.webm");
  GThread *thread2 = StartThread(pipe2, "http://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.ogv");
  
  // 이런 식으로.. 사용하는 게 아닌거같은데 ㅋㅋㅋ ㅠㅠ
  pipe1->Play();
  pipe2->Play();

  StopThread(pipe1, thread1);
  StopThread(pipe2, thread2);

  return 0;
}

static gpointer loop_func(gpointer data){
  Pipeline *pipe = static_cast<Pipeline>(data);

  g_main_loop_run(pipe->loop);

  return nullptr;
}

static GThread* StartThread(Pipeline *pipe,
                        const std::string &uri) {
  GMainContext *context;
  pipe = new Pipeline();
  pipe->CreatePipeline(uri);

  context = g_main_context_new();
  pipe->loop = g_main_loop_new(context, FALSE);
  g_main_context_unref(context);

  return g_thread_new(loop_func, pipe, TRUE, nullptr);
}

static void StopThread(Pipeline *pipe, GThread *thread){
  // TODO : loop는 pipeline마다 하나씩 가지게 할 거긴 하지만 
  // unref 같은 동작은 pipeline 밖에서 수행하므로 pipe 안에서
  // 가지고 있으면 안 될 것 같으니 따로 빼내기
  g_main_loop_quit(pipe->loop);
  g_thread_join(thread);
  g_main_loop_unref(pipe->loop);
}
