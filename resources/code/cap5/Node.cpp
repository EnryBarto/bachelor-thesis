Node::Node(const aiScene *_scene, aiNode *_node, vector<shared_ptr<GpuMesh>> &_meshes, vector<shared_ptr<Material>> &_materials)
{

  // Lettura dati del nodo corrente
  this->localModelMatrix = (mat4)_node->mTransformation;
  this->name = _node->mName;

  // Aggiunta mesh associate al nodo 
  for (int i = 0; i < _node->mNumMeshes; i++) {
    int meshId = _node->mMeshes[i];
    aiMesh *assimpMesh = _scene->mMeshes[meshId];

    unique_ptr<Mesh> mesh = make_unique<Mesh>(
      assimpMesh->mName, _meshes[meshId]
    ); // Creazione mesh dai dati di assimp

    mesh->setMaterial(
      _materials[assimpMesh->mMaterialIndex]
    ); // Copia del materiale condiviso

    this->meshes.push_back(move(mesh));
  }

  // Creazione ricorsiva nodi figli
  for (int i = 0; i < _node->mNumChildren; i++)
    this->childrenNode.push_back(make_unique<Node>(
      _scene, _node->mChildren[i], _meshes, _materials
    ));
}