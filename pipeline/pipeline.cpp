#include "pipeline.hpp"

namespace {
  GstFlowReturn pad_added_cb(){;}

} // namespace

Pipeline::Pipeline ()
  : loop(nullptr),
    pipeline(nullptr),
    audiosrc(nullptr),
    videosrc(nullptr),
    audiobin(nullptr),
    videobin(nullptr),
    audiosink(nullptr),
    videosink(nullptr) {}

Pipeline::~Pipeline(){
  if(pipeline) gst_object_unref(pipeline);
}

bool Pipeline::CreatePipeline(const std::string &uri){

  pipeline = gst_element_factory_make("playbin", "media-player");
  if(!pipeline) return false;

  g_object_set(pipeline, "uri", uri.c_str(), nullptr);

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

void Pipeline::Play(){
  gst_element_set_state(pipeline, GST_STATE_PLAYING);
}

void Pipeline::Pause(){
  gst_element_set_state(pipeline, GST_STATE_PAUSED);
}

void Pipeline::SetAppSrcCaps(const std::string &type,
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
