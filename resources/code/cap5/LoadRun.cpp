RunData* SndswEventManager::loadRun(int64_t runNumber) {
  
  { ... } // Estrazione e validazione della geometria 

  //Acquisizione della TChain ROOT tramite sndsw
  unique_ptr<TChain> newChain =
    snd::analysis_tools::GetTChain(runNumber);
  if (newChain->GetEntries() <= 0) throw runtime_error("Run empty.");
  this->chain = move(newChain);

  /* Setup dei branch ROOT sui vettori dell'esperimento
   * ed estrazione dei metadati da restituire */
  this->header = new SNDLHCEventHeader();
  { ... }
  this->loadedRun = runNumber;

  return new RunData(
    runNumber, date, fileName, this->chain->GetEntries()
  );
}