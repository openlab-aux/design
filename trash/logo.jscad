
// http://openjscad/#https://raw.github.com/openlab-aux/logo/master/trash/logo.jscad

function getParameterDefinitions() {
  return [
    { name: 'd', caption: 'd', type: 'float', initial: 16 },
    { name: 'h', caption: 'h', type: 'float', initial:  4 },
    { name: 's', caption: 's', type: 'int',   initial: 32 },
  ];
}

function openlab_logo(r, h, segs) {
  gray = 0.13;
  return (
    difference(
      difference(
        cylinder({
          r: r,
          h: h,
          fn: segs
        }),
        cylinder({
          r: r - r * (0.33),
          h: h * 2.01,
          fn: segs
        })
      ),
      translate([r / 2, r / 2, h / 2],
        cube({
          size: [r, r, h],
          center: true
        }))
    ).setColor(gray, gray, gray));
}

function main(arg) {
  return openlab_logo(arg.d, arg.h, arg.s);
}
