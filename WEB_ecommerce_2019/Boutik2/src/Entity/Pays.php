<?php

namespace App\Entity;

use Doctrine\ORM\Mapping as ORM;
use ApiPlatform\Core\Annotation\ApiResource;
/**
 * Pays
 *
 * @ORM\Table(name="pays")
 * @ORM\Entity
 */

 /**
 * ...
 * @ApiResource(
 *     collectionOperations={"get"},
 *     itemOperations={"get"}
 * )
 */
class Pays
{
    /**
     * @var int
     *
     * @ORM\Column(name="id", type="integer", nullable=false)
     * @ORM\Id
     * @ORM\GeneratedValue(strategy="IDENTITY")
     */
    private $id;

    /**
     * @var int
     *
     * @ORM\Column(name="nom", type="integer", nullable=false)
     */
    private $nom;

    /**
     * @var int
     *
     * @ORM\Column(name="prefix_tel", type="integer", nullable=false)
     */
    private $prefixTel;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getNom(): ?int
    {
        return $this->nom;
    }

    public function setNom(int $nom): self
    {
        $this->nom = $nom;

        return $this;
    }

    public function getPrefixTel(): ?int
    {
        return $this->prefixTel;
    }

    public function setPrefixTel(int $prefixTel): self
    {
        $this->prefixTel = $prefixTel;

        return $this;
    }


}
