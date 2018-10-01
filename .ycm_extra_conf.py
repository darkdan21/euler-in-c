flags = [
  '-Wall',
  '-Wextra',
  '-Werror',
  '-std=c11',
  '-isystem/usr/include/',
  '-Wno-unused-variable',
  '-Wno-unused-parameter'
  ]

SOURCE_EXTENSIONS = [ '.cpp', '.cxx', '.cc', '.c', ]

def FlagsForFile( filename, **kwargs ):
  return {
  'flags': flags,
  'do_cache': True
  }
