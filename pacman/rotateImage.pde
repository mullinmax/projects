PImage rotateImage_CW(PImage in) {
  PImage out = createImage(in.width, in.height, ARGB);
  in.loadPixels();
  out.loadPixels();
  for (int x = 0; x < in.width; x++) {
    for (int y = 0; y < in.height; y++) {
      out.pixels[y+x*out.height] = in.pixels[x+y*in.height];
    }
  }
  out.updatePixels();
  return out;
}