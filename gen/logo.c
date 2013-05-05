 /*
 * OpenLab e.V. Augsburg - logo.c
 *
 * References:
 * 
 * * 'Drawing Circles with Rational Quadratic Bezier Curves',
 *    Detlef Reimers, 2011-09-01.
 */

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include <math.h>

// #include <cairo/cairo.h>
// #include <cairo/cairo-svg.h> !!!

const double M_PI = 3.141592;

double d2r(double d) { return (d * (M_PI / 180.0)); }

int main(int argc, char *argv[]) {
	assert(argv[1]);
	assert(argv[2]);
	assert(argv[3]);
	assert(argv[4]);
	assert(argv[5]);

	int    d  = strtol(argv[1], NULL, 10);
	int    n  = strtol(argv[2], NULL, 10);
	double l  = strtod(argv[3], NULL);

	int debug = 7;
  int meta  = 0;

	if (argc >= 5) {
		debug = strtod(argv[4], NULL);
	}

	assert(debug >= 0);

	if (argc >= 6) {
		meta = strtod(argv[5], NULL);
	}

	assert(meta >= 0);

	int w   =  d, h = w;
	int pad = 21;

	// logo: round line width to multiple of two
	l = (int)(l * (w * 0.0125) * 2 * (37.0 / 100.0)) / 2;

	int r = (int)(((w - 1.75 * pad) - l * 2.0 - 1) / 2.0) + (l / 2.0) - 2;

	double a = (360.0 - 90.0) / (2.0 * n);
	double R = (int)(r / cos(d2r(a)));

	puts("<?xml version='1.0' standalone='yes'?>\n\n"
		 "<!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN'\n"
		 "  'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'>\n");

	printf("<svg xmlns           ='http://www.w3.org/2000/svg'\n"
		   "     xmlns:xlink     ='http://www.w3.org/1999/xlink'\n"
		   "     xmlns:sodipodi  ='http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd'\n"
		   "     xmlns:inkscape  ='http://www.inkscape.org/namespaces/inkscape'\n\n"
		   "     sodipodi:version='0.32'\n"
		   "     inkscape:version='0.46'\n"
		   "     sodipodi:docname='logo.svg'\n"
		   "     inkscape:output_extension='org.inkscape.output.svg.inkscape'\n\n"
		   "     id='svg2' version ='1.2' width='%d' height='%d'>\n\n", w, h);

	// '$ git tag -a v1.1 -m "release v1.1"' will result in: 'v1.1-2-g766d'
	printf("  <title>OpenLab e.V. - logo - version '%s'</title>\n", __GIT_VERSION);

  if (meta > 0) {
    puts("  <metadata id='license'\n"
         "    xmlns:rdf='http://www.w3.org/1999/02/22-rdf-syntax-ns#'\n"
         "    xmlns:dc='http://purl.org/dc/elements/1.1/'\n"
         "    xmlns:cc='http://creativecommons.org/ns#'>\n"
         "    <rdf:RDF>\n"
         "      <cc:Work rdf:about=''>");
    puts("        <dc:publisher>\n"
         "          <cc:Agent rdf:about='http://github.com/openlab-aux'>\n"
         "            <dc:title>OpenLab e.V. - Augsburg</dc:title>\n"
         "          </cc:Agent>\n"
         "        </dc:publisher>\n"
         "        <dc:creator>\n"
         "          <cc:Agent>\n"
         "            <dc:title>OpenLab Agent</dc:title>\n"
         "          </cc:Agent>\n"
         "        </dc:creator>\n"
         "        <dc:rights>\n"
         "          <cc:Agent>\n"
         "            <dc:title>OpenLab e.V. - Augsburg</dc:title>\n"
         "          </cc:Agent>\n"
         "        </dc:rights>");
    printf("      <dc:date>%s</dc:date>\n", __YYYY_MM_DD__);
    puts("        <dc:format>image/svg+xml</dc:format>\n"
         "        <dc:type    rdf:resource='http://purl.org/dc/dcmitype/StillImage'/>\n"
         "        <cc:license rdf:resource='http://creativecommons.org/licenses/by-sa/3.0'/>\n"
         "      </cc:Work>\n"
         "      <cc:License   rdf:about='http://creativecommons.org/licenses/by-sa/3.0/'>\n"
         "      <cc:permits   rdf:resource='http://creativecommons.org/ns#Reproduction'/>\n"
         "      <cc:permits   rdf:resource='http://creativecommons.org/ns#Distribution'/>\n"
         "      <cc:requires  rdf:resource='http://creativecommons.org/ns#Notice'/>\n"
         "      <cc:requires  rdf:resource='http://creativecommons.org/ns#Attribution'/>\n"
         "      <cc:permits   rdf:resource='http://creativecommons.org/ns#DerivativeWorks'/>\n"
         "      <cc:requires  rdf:resource='http://creativecommons.org/ns#ShareAlike'/>\n"
         "      </cc:License>\n"
         "    </rdf:RDF>\n"
         "  </metadata>\n");
  }

	/* wtf
	puts("\n  <script type='text/java'>\n"
		 "    <![CDATA[\n"
		 "      document.onload = function(){ alert('javascript!')});\n"
		 "      }\n"
		 "    ]]>\n"
		 "  </script>\n\n"
	);
	*/

	// pixel grid
	if (debug > 1) {
		puts("  <g style='stroke-width:0; fill:#0099CC; stroke-linecap: square;'>\n");
		for (int i = 0; i < w; i++) {
			double tmp = (i % w % 4 == 0 ? 0.0625 : 0.0125);
			
			printf("  <rect x='%f' y='%f' width='%f' height='%f' />\n",
				   i - tmp, -tmp, tmp,  h + tmp);
			
			printf("  <rect x='%f' y='%f' width='%f' height='%f'/>\n",
				   - tmp, i - tmp, w + tmp, tmp);
		}
		puts("</g>");
	}
 		
  // pixel chess raster
	if (debug > 7) {
		for (int i = 0; i < 64; i++) {
			for (int j = 0; j < 64; j++) {
				if (i % 2 == 0 && j % 2 == 0) {
					printf("<rect x='%d' y='%d' width='1' height='1'"
						   " style='stroke-width:0; fill:black'/>\n", i, j);
				}
			}
		}
	}
			
	// Android icon guides
	if (debug > 5) {
		printf("<g transform='translate(%.2f,%.2f)' "
			   "style='fill:none; "
			   "stroke:#99CC00; "
			   "stroke-dasharray:5; "
			   "stroke-width:1"
			   "'>",
			   w/2 - 0.5, h/2 - 0.5);

		// horizontal
		printf("  <path d='M%.2f %.2f L%.2f %.2f' />",
			   - w/2.0 + 0.5, - h/2.0 + pad, w/2.0,- h/2.0 + pad);
		printf("  <path d='M%.2f %.2f L%.2f %.2f' />",
			   - w/2.0 + 0.5,   h/2.0 - pad, w/2.0,  h/2.0 - pad);

		// vertical
		printf("  <path d='M%.2f %.2f L%.2f %.2f' />",
			   - w/2.0 + pad, -h/2.0 + 0.5, - w/2.0 + pad, h/2.0);
		printf("  <path d='M%.2f %.2f L%.2f %.2f' />",
			   w/2.0 - pad, -h/2.0 + 0.5,   w/2.0 - pad, h/2.0);

		printf("</g>");

	}

	// border
	if (debug > 1) {
		printf("<path d='M%.2f %.2f L%.2f,%.2f %.2f,%.2f %.2f,%.2f Z' "
			   "style='fill:none; stroke:black; stroke-width:1'/>",
			   0.5, 0.5, h - 0.5, 0.5, h - 0.5, w - 0.5, 0.5, h - 0.5);
	}

	// iconography - red inner and outer circle
	if (debug > 0) {
		printf("<g transform='translate(%.2f,%.2f)' "
			   "style='fill:none; stroke-width:1; stroke: #FF4444'>",
			   w/2.0, h/2.0);
		printf("  <circle r='%f' />", r + 0.5);
		printf("  <circle r='%f' />", R + 0.5);
		puts("</g>");
	}
		
	// logo
	printf("  <g id='logo' shape-rendering='geometricPrecision' text-rendering='geometricPrecision' image-rendering='optimizeQuality' transform='translate(%d,%d)'>\n", w / 2, h / 2);

	puts("    <g>");

/*	
	puts("      <animateTransform attributeType='xml'"
		 " attributeName='transform' type='rotate'"
		 " from='0 0 0' to='360 0 0' dur='20s' repeatCount='indefinite'"
		 "/>\n");
*/

	int x,y;

	x = 0; y = (int)(-r + 0.5);
	printf("      <path d='M%d %d ", x, y);

	double v;
	for (int i = 0; i < n; i++) {
		v = (int)(R + 0.5);
		int x1 =  v * sin(d2r((2*i+1)*a));
		int y1 = -v * cos(d2r((2*i+1)*a));

		v = (int)(r + 0.5);
		int x2 =  v * sin(d2r((2*(i+1))*a));
		int y2 = -v * cos(d2r((2*(i+1))*a));
		printf("Q%d %d %d %d ", x1, y1, x2, y2);
	}

	printf("' stroke-width='%.2f' style='fill:none; stroke:#444444' />\n", l);
	puts("  </g>");
	puts("</g>");

	// red center cross
	if (debug > 0) {
		printf("<g style='fill:#FF4444; stroke-linecap: square'>");
		printf("  <rect x='%d' y='%d' width='%.2f' height='%d' />",
			   w/2, h/2 - 4, 0.1, 8);

		printf("  <rect x='%d' y='%d' width='%d' height='%.2f' />",
			   w/2 - 4, h/2, 8, 0.1);
		puts("</g>");
	}

	puts("</svg>");

	fflush(stdout);

	return (EXIT_SUCCESS);
}
