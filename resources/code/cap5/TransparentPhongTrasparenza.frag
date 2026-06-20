// Derivata delle coordinate baricentriche
vec3 d = fwidth(barycentric);

// Lontananza dai bordi del triangolo per ogni componente
vec3 a3 = smoothstep(vec3(0.0), d * uEdgeThickness, barycentric);

// 0 se vicino a qualsiasi bordo
float edgeFactor = min(min(a3.x, a3.y), a3.z);

// Interpola tra alpha del bordo e alpha della faccia
float finalAlpha = mix(uEdgeAlpha, uFaceAlpha, edgeFactor);

// Colore finale del frammento
FragColor = vec4(vec3(baseColor), finalAlpha);