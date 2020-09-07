#include "pipeline.hpp"

namespace {
  GstFlowReturn pad_added_cb(){;}

} // namespace

void Pipeline ()
  : pipeline(nullptr),
    audioSrc(nullptr),
    videoSrc(nullptr),
    audioBin(nullptr),
    videoBin(nullptr),
    audioSink(nullptr),
    videoSink(nullptr) {}

bool Pipeline::createPipeline(){

  pipeline = gst_element_factory_make("playbin", "media-player");
  if(!pipeline) return false;

  // set the uri for the playing? or just set the appsrc
  // return

  /* TODO : change the pipeline to create dynamically */
  // pipeline = gst_pipeline_new("media-player");
  // if (!pipeline){
  // // log the error
  //  return;
  // }

  // create app src element(audio and video's one)
  // then set the app src

  // add the pad_added callback to the src?element
  return true;
}

void Pipeline::setAppSrcCaps(const std::string &type,
                             const std::string &codec) {
  GstCaps *caps = nullptr;
  if(typename == "video"){
    getVideoCaps(curVideoCodec, &caps);
    gst_app_src_set_caps(GST_APP_SRC(videoSrc));
  }
  else if(typename == "audio"){
    getAudioCaps(curAudioCodec, &caps);
    gst_app_src_set_caps(GST_APP_SRC(audioSrc));
  }  
}
