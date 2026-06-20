void PerspectiveProjection::computeProjectionMatrix() {
  this->matrix = glm::perspective(glm::radians(this->fovY), this->aspectRatio, this->nearPlane, this->farPlane);
}

void OrthographicProjection::computeProjectionMatrix() {
  // Calcolo dimensioni piano di vista
  float halfHeight =
    this->distance * std::tan(glm::radians(this->fovY * 0.5f));
  float halfWidth = this->aspectRatio * halfHeight;

  this->matrix = glm::ortho(-halfWidth, halfWidth, -halfHeight, halfHeight, this->nearPlane, this->farPlane);
}
