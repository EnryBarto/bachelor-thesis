void Node::updateGlobalModelMatrix(const mat4 &parentModelMatrix) {
  // Composizione matrice di modellazione globale
  this->globalModelMatrix = parentModelMatrix * this->localModelMatrix;

  // Chiamata ricorsiva sui nodi figli
  for (auto &node : this->childrenNode)
    node->updateGlobalModelMatrix(this->globalModelMatrix);

  // Salvataggio matrice calcolata nelle mesh
  for (auto &mesh : this->meshes)
    mesh->updateGlobalModelMatrix(this->globalModelMatrix);
}