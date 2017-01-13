PImage rotateImage_CC(PImage in) {
  PImage out = createImage(in.width, in.height, ARGB);
  in.loadPixels();
  out.loadPixels();
  for (int x = 0; x < in.width; x++) {
    for (int y = 0; y < in.height; y++) {
      out.pixels[(in.width-(x+1))*in.width+y] = in.pixels[x+y*in.width];
    }
  }
  out.updatePixels();
  return out;
}