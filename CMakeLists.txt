# ======================================================================
#  larpandora main build file
#
#  cd .../path/to/build/directory
#  source .../path/to/larpandora/ups/setup_for_development <-d|-p>
#  buildtool [-I /install/path] -bt[i] -jN
# ======================================================================

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
# cmake_policy(VERSION 3.19) ### MIGRATE-ACTION-COMPATIBILITY (migrate-3.13.00) - Uncomment to preserve compatibility with older CMake versions

find_package(cetmodules REQUIRED)
project(larpandora VERSION 09.12.15 LANGUAGES CXX)

# cetbuildtools contains our cmake modules

include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS CAUTIOUS
  WERROR
  NO_UNDEFINED
  EXTRA_FLAGS -pedantic -Wno-unused-local-typedefs
  )

cet_report_compiler_flags() ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - add args: REPORT_THRESHOLD VERBOSE

find_package(Eigen3 3.3...3.3.9 REQUIRED NO_MODULE)
find_package(messagefacility REQUIRED EXPORT)
find_package(canvas_root_io REQUIRED)
find_package(art REQUIRED EXPORT)
find_package(art_root_io REQUIRED EXPORT)
find_package(nug4 REQUIRED EXPORT)
find_package(PostgreSQL REQUIRED EXPORT)
find_package(ROOT COMPONENTS Core Tree Geom Graf3d GenVector REQUIRED EXPORT)
# these are minimum required versions, not the actual product versions
find_package( larcoreobj REQUIRED )
find_package( larcorealg REQUIRED )
find_package( larcore REQUIRED )
find_package( lardataobj REQUIRED )
find_package( lardataalg REQUIRED )
find_package( lardata REQUIRED )
find_package( larevt REQUIRED )
find_package( larsim REQUIRED )
find_package( larreco REQUIRED )
find_package( pandora REQUIRED )
find_package( larpandoracontent REQUIRED )

# macros for dictionary and simple_plugin
include(ArtDictionary)
include(ArtMake)
include(BuildPlugins)

cet_find_library( PANDORASDK NAMES PandoraSDK PATHS ENV PANDORA_LIB ) ### MIGRATE-ACTION-REQUIRED (migrate-3.13.00) - avoid: use find_package() with custom Find<pkg>.cmake for Spack compatibility
cet_find_library( PANDORAMONITORING NAMES PandoraMonitoring PATHS ENV PANDORA_LIB ) ### MIGRATE-ACTION-REQUIRED (migrate-3.13.00) - avoid: use find_package() with custom Find<pkg>.cmake for Spack compatibility

# source
add_subdirectory(larpandora)

# ups - table and config files

# packaging utility

cet_cmake_config()
