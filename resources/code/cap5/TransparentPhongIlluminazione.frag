// Normalizzazione dei vettori interpolati
vec3 N = normalize(illuminationData.N);
vec3 V = normalize(illuminationData.V);

// ----- COMPONENTE AMBIENTALE -----
vec3 ambient = uAmbientLightIntensity * material.ambient;

// Accumulatore delle componenti del modello di illuminazione
vec3 baseColor = ambient;

for (int i = 0; i < numLights; i++) {
  vec3 L = normalize(illuminationData.L[i]);
  vec3 H = normalize(L + V);

  // ----- COMPONENTE DIFFUSIVA -----
  float cos_theta = max(dot(L, N), 0);
  vec3 diffuse = lights[i].color * cos_theta * material.diffuse;

  // ----- COMPONENTE SPECULARE -----
  float cos_alfa = pow(max(dot(H, N), 0), material.shininess * 4);
  vec3 specular = lights[i].color * cos_alfa * material.specular;

  // Accumula il contributo dato dalla luce corrente
  baseColor += lights[i].power * (diffuse + specular);
}