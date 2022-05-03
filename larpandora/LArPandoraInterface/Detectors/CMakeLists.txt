art_make( EXCLUDE SimpleNeutrinoId_tool.cc
          LIB_LIBRARIES larcorealg_Geometry
                        larcore_Geometry_Geometry_service
                        PANDORASDK
                        PANDORAMONITORING
        ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - deprecated: use art_make_library(), art_dictonary(), and cet_build_plugin() with explicit source lists and plugin base types

install_headers()
install_source()
