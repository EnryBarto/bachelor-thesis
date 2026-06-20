void main() {
  for (int i = 0; i < 3; i++) {
    // Assegna una coordinata baricentrica diversa per ogni vertice
    barycentric = vec3(0.0);
    barycentric[i] = 1.0;

    // Riporta questi valori invariati 
    localPos = vLocalPos[i];
    gl_Position = gl_in[i].gl_Position;
    illuminationData = vIlluminationData[i];

    EmitVertex();
  }
  EndPrimitive();
}