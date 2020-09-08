pipeline_src= [ 'pipeline.cpp' ]

gst = dependency('gstreamer-1.0', version : '>=1.14')
base_dep = dependency('gstreamer-base-1.0', version : '>=1.14',
      fallback : ['gstreamer', 'gst_base_dep'])

pipeline_dep = declare_dependency(
    sources : pipeline_src,
    dependencies : [gst, base_dep]
)
