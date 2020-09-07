#ifndef _PIPELINE__
#define __PIPELINE__

#include <gst/gst.h>
#include <string>

class Pipeline {
  public:
    Pipeline();
    ~Pipeline();

    void createPipeline();
    void Play();
    void Pause();
    void Seek(guint32_t pos);
    void SetPlaybackRate(gdouble rate);
    void changeAudioCodec(const std::string &codec="");
    void changeVideoCodec(const std::string &codec="");

    guint32_t Position();

  private:
    void setAppSrcCaps(const std::string &type,
                       const std::string &codecname);

  private:
    GstElement *pipeline;
    GstElement *audioSrc;
    GstElement *videoSrc;
    GstElement *audioBin;
    GstElement *videoBin;
    GstElement *audioSink;
    GstElement *videoSink;
}



#endif //PIPELINE
