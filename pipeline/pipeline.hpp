#ifndef __PIPELINE__
#define __PIPELINE__

#include <gst/gst.h>
#include <string>

class Pipeline {
  public:
    Pipeline();
    ~Pipeline();

    bool CreatePipeline(const std::string &path="");
    void Play();
    void Pause();
    void Seek(int32_t pos);
    void SetPlaybackRate(gdouble rate);
    void ChangeAudioCodec(const std::string &codec);
    void ChangeVideoCodec(const std::string &codec);
    int32_t Position();

  private:
    void SetAppSrcCaps(const std::string &type,
                       const std::string &codecname);

  public:
    GMainLoop *loop;
  private:
    GstElement *pipeline;
    GstElement *audiosrc;
    GstElement *videosrc;
    GstElement *audiobin;
    GstElement *videobin;
    GstElement *audiosink;
    GstElement *videosink;
};

#endif //PIPELINE
