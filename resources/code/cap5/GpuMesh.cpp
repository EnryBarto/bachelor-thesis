GpuMesh::GpuMesh(vector<vec3>& vertices, vector<vec4>& colors, vector<vec3>& normals, vector<GLuint>& indices, vec3 anchorPosition) {

  { ... } // Controllo che le dimensioni dei vettori siano coerenti

  // Generazione e attivazione VAO
  glGenVertexArrays(1, &this->vao);
  glBindVertexArray(this->vao);

  // Generazione, attivazione e popolamento del VBO dei vertici
  glGenBuffers(1, &this->vboVertices);
  glBindBuffer(GL_ARRAY_BUFFER, this->vboVertices);
  glBufferData(GL_ARRAY_BUFFER, ..., vertices.data(), ...);

  // Caricamento del VBO dei vertici nel layer richiesto
  glVertexAttribPointer(VERTICES_LAYER, 3, GL_FLOAT, ...);
  glEnableVertexAttribArray(VERTICES_LAYER);
  
  { ... } // Stessa cosa per i VBO di colori e normali

  // Generazione, attivazione e riempimento EBO
  glGenBuffers(1, &this->eboIndices);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->eboIndices);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, ..., indices.data(), ...);

  { ... } // Unbind dei buffer
}

void GpuMesh::render(bool showAnchor) {
  glBindVertexArray(this->vao); // Bind del VAO
  glDrawElements(this->renderMode, this->numIndices, ...); // Render
}