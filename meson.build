project(
  'cmix',
  'c',
  version : '0.1',
  default_options: [
    'warning_level=3',
    'werror=true',
    'buildtype=debug',
    'debug=true',
    #'optimization=3',
    'c_std=c2x',
  ],
)

cmix_include = include_directories('include')

libmix_src = [
  'mix/src/version.c'
]

libmix = shared_library(
  'cmix',
  libmix_src,
  include_directories:  cmix_include,
)

asm_src = [
  'asm/src/main.c'
]

exe_asm = executable(
  'cmixasm',
  asm_src,
  link_with: [libmix],
  include_directories:  cmix_include,
)

vm_src = [
  'vm/src/main.c'
]


exe_vm = executable(
  'cmixvm',
  vm_src,
  link_with: [libmix],
  include_directories:  cmix_include,
)

