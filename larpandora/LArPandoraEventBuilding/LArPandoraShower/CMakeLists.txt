add_subdirectory(Tools)
add_subdirectory(Algs)

art_make(
  MODULE_LIBRARIES
  larpandora_LArPandoraEventBuilding
  larpandora_LArPandoraEventBuilding_LArPandoraShower_Algs
  ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.13.00) - deprecated: use art_make_library(), art_dictonary(), and cet_build_plugin() with explicit source lists and plugin base types


install_fhicl()
install_source()
