// I delta sono lo spostamento del mouse lungo i due assi
void Camera::moveParallel(float deltaX, float deltaY) {

  // Modifica lo spostamento proporzionalmente alla distanza
  float distance = glm::length(this->target - this->position);
  deltaX *= constants::factors::PAN_SPEED * distance;
  deltaY *= constants::factors::PAN_SPEED * distance;

  // Calcolo dei vettori che identificano il piano di spostamento
  vec3 direction = glm::normalize(this->target - this->position);
  vec3 right = glm::normalize(glm::cross(direction, this->worldUp));
  vec3 up = glm::normalize(glm::cross(right, direction));

  // Applica lo spostamento e ricalcola la matrice di vista
  this->position += up * deltaY + right * deltaX;
  this->target += up * deltaY + right * deltaX;
  this->recomputeMatrix();
}