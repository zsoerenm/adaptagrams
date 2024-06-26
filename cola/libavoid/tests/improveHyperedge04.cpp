#include "libavoid/libavoid.h"
using namespace Avoid;
int main(void) {
    Router *router = new Router(
            PolyLineRouting | OrthogonalRouting);
    router->setRoutingPenalty(segmentPenalty, 50);
    router->setRoutingPenalty(anglePenalty, 0);
    router->setRoutingPenalty(crossingPenalty, 200);
    router->setRoutingPenalty(clusterCrossingPenalty, 4000);
    router->setRoutingPenalty(fixedSharedPathPenalty, 9000);
    router->setRoutingPenalty((PenaltyType)5, 100);
    router->setRoutingOption(nudgeOrthogonalSegmentsConnectedToShapes, false);
    router->setRoutingOption(improveHyperedgeRoutesMovingJunctions, true);
    router->setRoutingOption(penaliseOrthogonalSharedPathsAtConnEnds, true);
    router->setRoutingOption(improveHyperedgeRoutesMovingJunctions, false);
    router->setRoutingOption(improveHyperedgeRoutesMovingAddingAndDeletingJunctions, true);
    router->setRoutingParameter(idealNudgingDistance, 25);

    Polygon poly2(4);
    poly2.ps[0] = Point(50354, 50975);
    poly2.ps[1] = Point(50354, 51060);
    poly2.ps[2] = Point(50296, 51060);
    poly2.ps[3] = Point(50296, 50975);
    ShapeRef *shapeRef2 = new ShapeRef(router, poly2, 2);
    new ShapeConnectionPin(shapeRef2, 1, 0.5, 1, true, 10, (ConnDirFlags) 1);

    Polygon poly39761567(4);
    poly39761567.ps[0] = Point(50754, 50975);
    poly39761567.ps[1] = Point(50754, 51060);
    poly39761567.ps[2] = Point(50696, 51060);
    poly39761567.ps[3] = Point(50696, 50975);
    ShapeRef *shapeRef39761567 = new ShapeRef(router, poly39761567, 39761567);
    new ShapeConnectionPin(shapeRef39761567, 1, 0.5, 0, true, 10, (ConnDirFlags) 1);

    Polygon poly115776716(4);
    poly115776716.ps[0] = Point(51504, 50975);
    poly115776716.ps[1] = Point(51504, 51060);
    poly115776716.ps[2] = Point(51446, 51060);
    poly115776716.ps[3] = Point(51446, 50975);
    ShapeRef *shapeRef115776716 = new ShapeRef(router, poly115776716, 115776716);
    new ShapeConnectionPin(shapeRef115776716, 1, 0.5, 0, true, 10, (ConnDirFlags) 1);

    Polygon poly238475293(4);
    poly238475293.ps[0] = Point(50554, 50975);
    poly238475293.ps[1] = Point(50554, 51060);
    poly238475293.ps[2] = Point(50496, 51060);
    poly238475293.ps[3] = Point(50496, 50975);
    ShapeRef *shapeRef238475293 = new ShapeRef(router, poly238475293, 238475293);
    new ShapeConnectionPin(shapeRef238475293, 1, 0.5, 0, true, 10, (ConnDirFlags) 1);

    Polygon poly430971008(4);
    poly430971008.ps[0] = Point(51004, 50975);
    poly430971008.ps[1] = Point(51004, 51060);
    poly430971008.ps[2] = Point(50946, 51060);
    poly430971008.ps[3] = Point(50946, 50975);
    ShapeRef *shapeRef430971008 = new ShapeRef(router, poly430971008, 430971008);
    new ShapeConnectionPin(shapeRef430971008, 1, 0.5, 0, true, 10, (ConnDirFlags) 1);

    JunctionRef *junctionRef513246008 = new JunctionRef(router, Point(50925, 50700), 513246008);
    /*
    // This may be useful if junction pins are modified.
    new ShapeConnectionPin(junctionRef513246008, 2147483646, (ConnDirFlags) 15);
    */
    JunctionRef *junctionRef4 = new JunctionRef(router, Point(50725, 50725), 4);

    ConnRef *connRef3 = new ConnRef(router, 3);
    ConnEnd srcPt3(shapeRef2, 1);
    connRef3->setSourceEndpoint(srcPt3);
    ConnEnd dstPt3(junctionRef513246008);
    connRef3->setDestEndpoint(dstPt3);
    connRef3->setRoutingType((ConnType)2);
    
    ConnRef *connRef5 = new ConnRef(router, 5);
    ConnEnd srcPt5(junctionRef4);
    connRef5->setSourceEndpoint(srcPt5);
    ConnEnd dstPt5(junctionRef513246008);
    connRef5->setDestEndpoint(dstPt5);
    connRef5->setRoutingType((ConnType)2);

    ConnRef *connRef513246009 = new ConnRef(router, 513246009);
    ConnEnd srcPt513246009(shapeRef39761567, 1);
    connRef513246009->setSourceEndpoint(srcPt513246009);
    ConnEnd dstPt513246009(junctionRef4);
    connRef513246009->setDestEndpoint(dstPt513246009);
    connRef513246009->setRoutingType((ConnType)2);

    ConnRef *connRef513246010 = new ConnRef(router, 513246010);
    ConnEnd srcPt513246010(junctionRef513246008);
    connRef513246010->setSourceEndpoint(srcPt513246010);
    ConnEnd dstPt513246010(shapeRef430971008, 1);
    connRef513246010->setDestEndpoint(dstPt513246010);
    connRef513246010->setRoutingType((ConnType)2);

    ConnRef *connRef513246011 = new ConnRef(router, 513246011);
    ConnEnd srcPt513246011(junctionRef4);
    connRef513246011->setSourceEndpoint(srcPt513246011);
    ConnEnd dstPt513246011(shapeRef238475293, 1);
    connRef513246011->setDestEndpoint(dstPt513246011);
    connRef513246011->setRoutingType((ConnType)2);

    ConnRef *connRef513246012 = new ConnRef(router, 513246012);
    ConnEnd srcPt513246012(shapeRef115776716, 1);
    connRef513246012->setSourceEndpoint(srcPt513246012);
    ConnEnd dstPt513246012(junctionRef513246008);
    connRef513246012->setDestEndpoint(dstPt513246012);
    connRef513246012->setRoutingType((ConnType)2);
    router->processTransaction();
    router->outputDiagram(IMAGE_OUTPUT_PATH "output/improveHyperedge04");

    bool overlaps = router->existsOrthogonalSegmentOverlap(true);
    delete router;
    return (overlaps) ? 1 : 0;
};
