void Object::sortMeshes(glm::vec3 point) {
  std::sort(this->meshes.begin(), this->meshes.end(),
    [point](Mesh* a, Mesh* b) {
      float distA = glm::distance2(a->getAnchor(), point);
      float distB = glm::distance2(b->getAnchor(), point);
      return distA > distB;
    });
}