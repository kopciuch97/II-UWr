<?php

require_once __DIR__ . '/../vendor/autoload.php';

use src\Product;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use src\DataManager;

$dataManager = new DataManager(__DIR__ . '/../src/Data/');
$app = new Silex\Application();

$app->get('/products/{id}', function ($id) use($app, $dataManager){
    return $dataManager->getContent($id);
});

$app->get('/products', function() use($app){
    $path = __DIR__ . '/../src/Data/';
    $files = array_diff(scandir($path), array('..', '.'));
    $result = array();
    foreach ($files as $file){
        array_push($result, json_decode(file_get_contents($path . $file), JSON_PRETTY_PRINT));
    }
    return new Response(json_encode($result), 200);
});

$app->post('/products', function (Request $request) {
    $id = file_get_contents(__DIR__ . '/../src/counter');
    $product = new Product(
        $id,
        $request->get('name'),
        $request->get('value'),
        $request->get('currency')
    );
    file_put_contents(__DIR__ . '/../src/counter', $id + 1);
    file_put_contents(__DIR__ . '/../src/Data/' . $id . '.json', json_encode(array(
        'id' => $product->getId(),
        'name' => $product->getName(),
        'price' => $product->getPrice())));
    return new Response('Dodano nowy produkt o id: ' . $id, 200);
});


$app->put('/products/{id}', function (Request $request, $id) use ($app) {
    $product = new Product(
        $id,
        $request->get('name'),
        $request->get('value'),
        $request->get('currency')
    );
    file_put_contents(__DIR__ . '/../src/Data/' . $id . '.json', json_encode(array(
        'id' => $product->getId(),
        'name' => $product->getName(),
        'price' => $product->getPrice()), JSON_PRETTY_PRINT));
    return new Response("Zaktualizowano obiekt o id: " . $id , 200);
});

$app->delete('/products/{id}', function ($id) use ($app) {
    $file = __DIR__ . "/../src/Data/" . $id . '.json';
    unlink($file);
    return new Response("Usunieto pozycje o id: " . $id, 200);

});
$app->get('/', function () use ($app) {
    return $app->redirect('/products');
});

$app->error(function (\Exception $e, Request $request, $code) {
    switch ($code) {
        case 404:
            $message = 'The requested page could not be found.';
            break;
        default:
            $message = 'We are sorry, but something went terribly wrong.';
    }

    return new Response($message);
});

$app->run();

