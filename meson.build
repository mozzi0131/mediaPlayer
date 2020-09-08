project('mediaplayer', 'cpp')

subdir('pipeline')

gst = dependency('gstreamer-1.0', version : '>=1.14')
src = ['runner.cpp']

executable('player', src,
            dependencies : [gst, pipeline_dep])
