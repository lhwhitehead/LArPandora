add_subdirectory(Cheating)

art_make(TOOL_LIBRARIES
  larpandora_LArPandoraEventBuilding_LArPandoraShower_Algs
  larreco_Calorimetry
  larpandora_LArPandoraInterface_Detectors
  LArPandoraContent
  )

install_headers()
install_source()
install_fhicl()
