add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "."})

set_languages("gnu23")
set_warnings("all", "error")

--  common functions, structures for all the MIX related stuff
--  all of it is declared right here.
add_includedirs("include")

target("libmix")
    set_kind("shared")
    add_files("mix/src/*.c")

target("mixasm")
    set_kind("binary")
    add_includedirs("asm")
    add_deps("libmix")
    add_files("asm/src/*.c")

target("mixvm")
  set_kind("binary")
  add_includedirs("vm")
  add_deps("libmix")
  add_files("vm/src/*.c")

