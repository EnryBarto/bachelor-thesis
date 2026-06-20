/* ---- CLUSTER SU PIANI SCIFI ---- */
this->scifiPlanes = snd::analysis_tools::FillScifi(..);
vector<vector<snd::analysis_tools::Cluster>> scifiClusters(this->config->scifi_n_stations);
DetectorData *detector = new DetectorData("SciFi");
eventDataToReturn->addDetector(detector);

// Calcolo dei cluster
for (auto &p : this->scifiPlanes)
  if (isValid(p.GetStation() - 1)) {
    auto planeClusters =
      ClustersPositions(p.GetHits(), clustConf...);
    { ... } // Aggiunta cluster trovati al vettore
  }

// Aggiunta dei cluster al DetectorData
for (int i=0; i < this->config->scifi_n_stations; ++i)
  for (auto &c : scifiClusters[i])
    detector->addHit(new HitData(c.center.X(), ...));