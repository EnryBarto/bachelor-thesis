void main() {
  vLocalPos = aPos;

  // Posizione del vertice in Clip space 
  gl_Position = Projection * View * Model * vec4(aPos, 1.0);

  // Posizione del vertice in VCS
  vec4 eyePosition = View * Model * vec4(aPos, 1.0);

  // Vettore normale e di vista del vertice in VCS
  vIlluminationData.N =
    normalize(transpose(inverse(mat3(View * Model))) * vertexNormal);
  vIlluminationData.V = normalize(-eyePosition.xyz);

  for (int i = 0; i < numLights; i++) {
    // Vettore che dal vertice va alla luce in VCS
    vec4 eyeLightPos = View * vec4(lights[i].position, 1.0);
    vIlluminationData.L[i] = normalize((eyeLightPos -eyePosition).xyz);
  }
}