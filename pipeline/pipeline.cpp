#include "pipeline.hpp"

#include <gst/app/gstappsrc.h>

namespace {
  void GetVideoCaps(GstCaps **caps){;}
  void GetAudioCaps(GstCaps **caps){;}
  GstFlowReturn pad_added_cb(){ return GST_FLOW_OK;}

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
  // unique_ptr로 널리 쓰이는 local info 관리하는 게 나을듯?
  if(type == "video"){
    GetVideoCaps(&caps);
    gst_app_src_set_caps(GST_APP_SRC(videosrc), caps);
  }
  else if(type == "audio"){
    GetAudioCaps(&caps);
    gst_app_src_set_caps(GST_APP_SRC(audiosrc), caps);
  }
  gst_caps_unref(caps);
}
