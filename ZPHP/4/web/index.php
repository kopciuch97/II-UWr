<?php

require_once __DIR__.'/../vendor/autoload.php';
use src\Product;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;

$app = new Silex\Application();

//$app->get('/products/{id}', function ($app, $id){

//});

//$app->get('/products', function ($app, $id){
//});

$app->post('/products', function(Request $request){
    $product = new Product(
        $request->request->get('id'),
        $request->request->get('name'),
        $request->request->get('value'),
        $request->request->get('currency')
    );

    file_put_contents('qwerty.txt', 'q');
    //json_encode($product));
    return new Response($product->getName(),200);
});


$app->put('/products/{id}', function ($app, $id){
});

$app->delete('/products/{id}', function ($app, $id){
});



$app->run();