project('mediaplayer', 'cpp')

gst = dependency('gstreamer-1.0', version : '>=1.14')
incdir = include_directories('pipeline')
src = ['runner.cpp']

executable('player', src,
            dependencies : gst)
