Material::Material(vec3 color) {
  this->baseColor = color;
  this->ambient = vec4(color * 0.5f, 1.0f);
  this->diffuse = vec4(color * 0.8f, 1.0f);
  this->specular = vec4(color * 0.3f + vec3(0.3f), 1.0f);
  this->shininess = 32.0f;
}